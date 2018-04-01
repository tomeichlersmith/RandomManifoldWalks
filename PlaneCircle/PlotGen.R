# 1-dimensional data analysis
# Useful in symmetrical cases where the problem can be reduced to one dimension
# Import data in two column table: { point , distance of walk to escape }
# Plots, "averages" data by interpolating

# Input data file from command line
#!/usr/bin/env Rscript
args = commandArgs(trailingOnly = TRUE)

if ( length(args) != 1 ) {
  stop("ERROR:\tInputs not formatted correctly. Should be \"Filename\"", call. = FALSE)
}

# Get filename
filename <- "PlaneCircle_L05_N2000_S005" #args[1]

library(ggplot2)

#Construct file path
datadir <- "~/CodeProjects/MathDHP_201718/RandomManifoldWalks/PlaneCircle/data/"
sum_fp <- paste( datadir , filename , "_summary.csv" , sep = "" )
sum_walk <- read.csv( sum_fp )

#Default ggplot
gp <- ggplot(data = sum_walk , aes( x = U , y = V ) ) + xlab("Starting U Coordinate") +
  ylab("Starting Y Coordinate") # + zlab("Length of Walk to Escape")
gp + geom_raster(aes(fill = MeanWalkLen)) +
  scale_fill_gradient(name = "Mean Length\nto Escape",
                      trans = "log", #Change color scale to log
                      breaks = c(0.1,1,10,100), #Set markers on log scale
                      limits = c(0.01,150)) #Set limits (required to set markers)

#Export to pdf file
plotpath <- paste( datadir , filename , ".pdf" , sep = "" )
pdf( plotpath ) #Open File Connection
gp
dev.off() #Stop Printing

#Data Clean Up
rm( sum_walk , gp )

