# 1-dimensional data analysis
# Useful in symmetrical cases where the problem can be reduced to one dimension
# Import data in two column table: { point , distance of walk to escape }
# Plots, "averages" data by interpolating

library(ggplot2)

#Construct file path
fp <- file.path("~/CodeProjects/MathDHP_201718/Data", "Plane_UnitCircle.csv")
#read in csv file to a data frame
raw_walk <- read.csv(fp)

raw_walk$R <- sqrt((raw_walk$U)^2+(raw_walk$V)^2)

#ggplot to plot
plotpts <- ggplot( raw_walk , aes( x = R , y = WalkLen) ) +
  geom_point( size = 0.5 , alpha = 0.1 )
#model <- lm(data.y ~ poly(data.x,n))
# n - polynomial degree