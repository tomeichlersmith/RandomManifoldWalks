# 1-dimensional data analysis
# Useful in symmetrical cases where the problem can be reduced to one dimension
# Import data in two column table: { point , distance of walk to escape }
# Plots, "averages" data by interpolating

# Input data file from command line
#!/usr/bin/env Rscript
args = commandArgs(trailingOnly = TRUE)

if ( length(args) > 2 ) {
  stop("ERROR:\tInputs not formatted correctly. Should be \"Filename [T/F]\"", call. = FALSE)
}

# Get filename
filename <- args[1]

# Get whether to include raw walks
includeraw <- FALSE
if ( args[2] == "T" ) {
  includeraw <- TRUE;
}

library(ggplot2)

#Construct file path
datadir <- "~/CodeProjects/MathDHP_201718/RandomManifoldWalks/Plane/data/"
if ( includeraw ) {
  raw_fp <- paste( datadir , filename , ".csv" , sep = "" )
  raw_walk <- read.csv( raw_fp )
}
sum_fp <- paste( datadir , filename , "_summary.csv" , sep = "" )
sum_walk <- read.csv( sum_fp )

#Default ggplot
gp <- ggplot() + geom_point( data = sum_walk , aes( x = R , y = MeanWalkLen ) ,
    alpha = 0.3 , color = 'royalblue4' , shape = 1 ) +
  geom_smooth( data = sum_walk , aes( x = R , y = MeanWalkLen ) ,
    color = 'royalblue')
if ( includeraw ) {
  gp <- gp + geom_point( data = raw_walk , aes( x = R , y = WalkLen ) ,
    size = 0.05 , alpha = 0.01 , color = 'red4' , shape = 1 ) +
  geom_smooth( data = raw_walk , aes( x = R , y = WalkLen ) ,
    color = 'red')
}
gp <- gp + xlab("Starting Radius") +
  ylab("Length of Walk to Escape")

#Export to pdf file
plotpath <- paste( datadir , filename , ".pdf" , sep = "" )
pdf( plotpath ) #Open File Connection
gp
dev.off() #Stop Printing

#Data Clean Up
rm( sum_walk , gp )
if ( includeraw ) {
  rm( raw_walk )
}
