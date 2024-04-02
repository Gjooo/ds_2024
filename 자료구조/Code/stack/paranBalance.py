from liststack import ListStack

def paranBalance(str):
    st = ListStack()
    for i, s in enumerate(str):
        if s== ')' and st.isEmpty():
            return False
        elif s == '(':
            st.push('(')
        elif s == ')':
            st.pop()
    return st.isEmpty()

print(paranBalance('((800/(3+5*2)))'))
print(paranBalance("(82+2)/4"))
print(paranBalance('(91*(40-35)+2)'))
print(paranBalance('(91*(40-35)+2'))