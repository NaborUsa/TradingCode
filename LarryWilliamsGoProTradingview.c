// This source code is subject to the terms of the Mozilla Public License 2.0 at https://mozilla.org/MPL/2.0/
// © bharatTrader

//@version=4
study("Public & Pro Action", shorttitle="Public&Pro")

//Input
averageLength = input(defval=14, title="Length of Average", type=input.integer, minval=1)
plotMode = input(title="Plot Mode", defval="Line", options=["Line", "Bar", "Advanced"])

//Set up
public = close[1] - open
pro =  close - open

defaultMode = plotMode == "Line"
advancedMode = plotMode == "Advanced"
barMode = plotMode == "Bar"
avg_public = sma(public, averageLength)
avg_pro = sma(pro, averageLength)
res = avg_pro - avg_public
priceSMA = sma(close, 2)

//Plot
plot(defaultMode ? avg_public : na, color=color.red, title="Public", linewidth=2)
plot(defaultMode ? avg_pro : na, color=color.green, title="Pro", linewidth=2)

plotColor = close > priceSMA and res > 0 ? color.green : close < priceSMA and res < 0 ? color.red : color.gray
plot(advancedMode ? res : na, style=plot.style_columns, color=plotColor, title="Advanced Plot")

barColor = res >= 0 ? color.teal : color.maroon
plot(barMode? 0 : na, linewidth=20, color=barColor)
