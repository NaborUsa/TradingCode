// This Pine Script® code is subject to the terms of the Mozilla Public License 2.0 at https://mozilla.org/MPL/2.0/
// © Naborf

//@version=6
indicator("LarryProGo")

averageLength = input(defval = 14, title = "Average Length")

public = close[1] - open
pro = close - open

avg_public = ta.sma(public, averageLength)
avg_pro = ta.sma(pro, averageLength)
res =avg_pro - avg_public
priceSMA = ta.sma(close, averageLength)

plot(avg_public, title = "Avg Public", color=color.red)
plot(avg_pro, title = "Avg Pro" , color=color.green)
