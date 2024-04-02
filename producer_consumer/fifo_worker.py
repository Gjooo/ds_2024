from listQueue import ListQueue
import threading
import time

class Producer:
    def __init__(self, items, q1):
            self.q1 = q1
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
                self.q1.enqueue(item)
                if item!=None:
                    print("Arrived:", item)
            else:
                break
            
        print("Producer is dying")

    def start(self):
        self.worker.start()

    def finish(self):
        self.__alive = False
        self.worker.join()

class Consumer:
    def __init__(self, q1):
        self.q1 = q1
        self.__alive = True
        self.worker = threading.Thread(target=self.run)

    def run(self):
        while not q1.isEmpty:
            pass
        while True:
            time.sleep(1)
            if self.__alive:
                if not self.q1.isEmpty():
                    print("Boarding:", self.q1.dequeue())
            else:
                break
        print("Consumer is dying")

    def start(self):
        self.worker.start()

    def finish(self):
        self.__alive = False
        self.worker.join()

if __name__ == "__main__":
    
    q1 = ListQueue()
    
    customers = []
    with open("customer.txt", 'r') as file:
        lines = file.readlines()
        for line in lines:
            customer = line.split()
            customers.append(customer)

    # FIFO
    names = []
    for c in customers:
        names.append(c[1])

    producer = Producer(names, q1)

    # Priority 
    # producer = Producer(customers)
    consumer = Consumer(q1)    
    producer.start()
    consumer.start()
    time.sleep(10)
    producer.finish()
    consumer.finish()
