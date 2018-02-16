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

filename <- args[1]

library(ggplot2)

#Construct file path
datadir <- "~/CodeProjects/MathDHP_201718/RandomManifoldWalks/data/"
fp <- paste( datadir , filename , sep = "" )
#read in csv file to a data frame
raw_walk <- read.csv(fp)

#Default ggplot
gp <- ggplot( raw_walk , aes( x = PolAng , y = WalkLen ) ) +
  geom_bin2d( alpha = 0.7 )

#ggplot does the fit
gp <- gp + geom_smooth( color = "black" )

#Export to pdf file
plotname <- gsub( "csv" , "pdf" , filename)
plotpath <- paste( datadir , plotname , sep = "" )
pdf( plotpath ) #Open File Connection
gp
dev.off() #Stop Printing

#Data Clean Up
rm( raw_walk , gp )
