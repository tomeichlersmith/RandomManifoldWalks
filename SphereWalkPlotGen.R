# 1-dimensional data analysis
# Useful in symmetrical cases where the problem can be reduced to one dimension
# Import data in two column table: { point , distance of walk to escape }
# Plots, "averages" data by interpolating

# Input data file from command line
#!/usr/bin/env Rscript
args = commandArgs(trailingOnly = TRUE)

if ( length(args) != 1 ) {
  stop("ERROR:\tData File not provided", call. = FALSE)
}

# Get filename
filename <- args[1]
filename <- "Sphere_L03_N50_S005"

library(ggplot2)

#Construct file path
datadir <- "~/CodeProjects/MathDHP_201718/RandomManifoldWalks/data/"
raw_fp <- paste( datadir , filename , ".csv" , sep = "" )
sum_fp <- paste( datadir , filename , "_summary.csv" , sep = "" )
#read in csv file to a data frame
raw_walk <- read.csv( raw_fp )
sum_walk <- read.csv( sum_fp )

#Default ggplot
gp <- ggplot() +
  geom_point( data = raw_walk , aes( x = PolAng , y = WalkLen ) , size = 0.05 , alpha = 0.05 , color = 'slateblue1' , shape = 1 ) +
  geom_point( data = sum_walk , aes( x = PolAng , y = MeanWalkLen ) , shape = 1 , alpha = 0.3 ) +
  geom_smooth( data = raw_walk , aes( x = PolAng , y = WalkLen ) , color = 'blue' ) +
  geom_smooth( data = sum_walk , aes( x = PolAng , y = MeanWalkLen ) , color = 'black' )
gp <- gp + xlab("Starting Polar Angle") +
  ylab("Length of Walk to Escape")

#Export to pdf file
plotname <- gsub( "csv" , "pdf" , filename)
plotpath <- paste( datadir , plotname , sep = "" )
pdf( plotpath ) #Open File Connection
gp
dev.off() #Stop Printing

#Data Clean Up
rm( raw_walk , gp )
