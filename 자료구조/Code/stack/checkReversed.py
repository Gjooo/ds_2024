from liststack import ListStack

def checkReversed(str) -> bool:
    st = ListStack()
    i = 0
    while (str[i] != '$'):
        st.push(str[i])
        i+=1
    i+=1
    
    while (i < len(str)):
        if not (str[i]==st.pop()):
            return False
        i+=1
    return True

print(checkReversed('abc$cba'))
print(checkReversed('abc$cca'))