import sys

# jh
def jhbuy():
    global jhmoney, jhstock
    for i in range(14):
        if jhmoney == 0:
            break
        if jhmoney >= pricelist[i]:
            stock = int(jhmoney/pricelist[i])
            jhstock += stock
            jhmoney -= pricelist[i] * stock 
    return jhmoney + jhstock * pricelist[13] 

#sm
def continuity(day):
    inc, dec = 0, 0
    for i in range(3, 0, -1):
        if pricelist[day - i] < pricelist[day - i + 1]:
            inc += 1
            dec = 0
        elif pricelist[day - i] > pricelist[day - i + 1]:
            dec += 1
            inc = 0
    return inc, dec
        
def smbuy():
    global smmoney, smstock
    for day in range(3, 14):
        inc, dec = continuity(day)
        if inc == 3 and smstock > 0:
            smmoney += smstock * pricelist[day]
            smstock = 0
        elif dec == 3 and smmoney >= pricelist[day]:
            stock = int(smmoney/pricelist[day])
            smstock += stock
            smmoney -= pricelist[day] * stock
    return smmoney + smstock * pricelist[13] 

money = int(input())
pricelist = list(map(int, sys.stdin.readline().split()))

jhmoney, smmoney = money, money
jhstock, smstock = 0, 0

jh = jhbuy()
sm = smbuy()
if jh > sm:
    print("BNP")
elif jh < sm:
    print("TIMING")
else:
    print("SAMESAME")