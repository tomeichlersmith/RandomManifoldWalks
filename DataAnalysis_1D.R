# 1-dimensional data analysis
# Useful in symmetrical cases where the problem can be reduced to one dimension
# Import data in two column table: { point , distance of walk to escape }
# Plots, "averages" data by interpolating

library(ggplot2)

#Construct file path
fp <- file.path("~/CodeProjects/MathDHP_201718/Data", "Sphere_0300000_0050000_50.csv")
#read in csv file to a data frame
raw_walk <- read.csv(fp)

#Default ggplot fit
gp <- ggplot( raw_walk , aes( x = PolAng , y = WalkLen ) ) +
  geom_point( size = 0.5 , alpha = 0.05 )
gp + geom_smooth()

# #Personal Model
# model <- loess( R ~ WalkLen , data = raw_walk )
# xrange <- range(  raw_walk$R )
# xseq <- seq( from = xrange[1] , to = xrange[2] , length = 100 )
# pred <- predict( model , newdata = data.frame( WalkLen = xseq ) , se = TRUE )
# y = pred$fit
# ci <- pred$se.fit * qt( 0.95 / 2 + 0.5 , pred$df )
# ymin = y - ci
# ymax = y + ci
# loess.DF <- data.frame( x = xseq , y , ymin , ymax , se = pred$se.fit )
# 
# gp +
#   geom_smooth( aes_auto(loess.DF) , data = loess.DF , stat = "identity" )

