from listQueue import ListQueue
import threading
import time

class Producer:
    def __init__(self, items, norm, gold, plat):
            self.norm = norm
            self.gold = gold
            self.plat = plat
            self.__alive = True
            self.items = items
            self.pos = 0
            self.worker = threading.Thread(target=self.run)

    def get_item(self):
        if self.pos < len(self.items):
            item = self.items[self.pos]
            self.pos += 1
            return item
        else:
            return None

    def run(self):
        
        while True:
            time.sleep(0.2)
            if self.__alive:
                item = self.get_item()
                if item==None:
                    continue
                if item[0] == '1':
                    self.norm.enqueue(item[1])
                if item[0] == '2':
                    self.gold.enqueue(item[1])
                if item[0] == '3':
                    self.plat.enqueue(item[1])
                print("Arrived:", item[1])
            else:
                break
            
        print("Producer is dying")

    def start(self):
        self.worker.start()

    def finish(self):
        self.__alive = False
        self.worker.join()

class Consumer:
    def __init__(self, norm, gold, plat):
        self.norm = norm
        self.gold = gold
        self.plat = plat
        self.__alive = True
        self.worker = threading.Thread(target=self.run)

    def run(self):
        while True:
            time.sleep(1)
            if self.__alive:
                if not self.plat.isEmpty():
                    print("Boarding:", self.plat.dequeue())
                elif not self.gold.isEmpty():
                    print("Boarding:", self.gold.dequeue())
                elif not self.gold.isEmpty():
                    print("Boarding:", self.norm.dequeue())
            else:
                break
        print("Consumer is dying")

    def start(self):
        self.worker.start()

    def finish(self):
        self.__alive = False
        self.worker.join()

if __name__ == "__main__":
    
    norm = ListQueue()
    gold = ListQueue()
    plat = ListQueue()
    
    customers = []
    with open("customer.txt", 'r') as file:
        lines = file.readlines()
        for line in lines:
            customer = line.split()
            customers.append(customer)

    # Priority 
    producer = Producer(customers, norm, gold, plat)
    consumer = Consumer(norm, gold, plat)    
    producer.start()
    consumer.start()
    time.sleep(10)
    producer.finish()
    consumer.finish()
