# Larry Williams Pro-Go
# Assembled by BenTen at UseThinkScript.com
# Converted from https://www.tradingview.com/script/R9iKLUAp-Public-Pro-Action/

declare lower;

input averageLength = 14;
input paintbar = no;

def public = close[1] - open;
def pro =  close - open;

def avg_public = simpleMovingAvg(public, averageLength);
def avg_pro = simpleMovingAvg(pro, averageLength);
def res = avg_pro - avg_public;
def priceSMA = simpleMovingAvg(close, averageLength);

plot pu = avg_public;
plot pr = avg_pro;

pu.AssignValueColor(color.red);
pr.AssignValueColor(color.green);

def condition1 = pu > pr;

assignPriceColor(if paintbar and condition1 then color.red else if paintbar and !condition1 then color.green else color.current);
