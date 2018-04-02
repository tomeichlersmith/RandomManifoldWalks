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
nbins <- 100
gp <- ggplot( data = raw_walk , aes( x = R , y = WalkLen ) ) + 
  stat_summary_bin( fun.y = median, #Median points
                    bins = nbins,
                    geom = "line",
                    size = 1.1,
                    color = "black") +
  stat_summary_bin( fun.y = function(y) { quantile(y,0.25) }, #Lower quartile points
                    bins = nbins,
                    geom = "line",
                    color = "slategrey") +
  stat_summary_bin( fun.y = function(y) { quantile(y,0.75) }, #Upper quartile points
                    bins = nbins,
                    geom = "line",
                    color = "slategrey") +
  xlab("Starting Radius") +
  ylab("Median Length of Walk to Escape") +
  theme_bw()

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
