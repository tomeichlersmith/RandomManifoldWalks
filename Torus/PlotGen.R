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
filename <- args[1]

library(ggplot2)

#Construct file path
datadir <- "~/CodeProjects/MathDHP_201718/RandomManifoldWalks/PlaneCircle/data/"
raw_fp <- paste( datadir , filename , ".csv" , sep = "" )
sum_fp <- paste( datadir , filename , "_summary.csv" , sep = "" )

# ggplot for summary
# sum_walk <- read.csv( sum_fp )
# gp_sum <- ggplot(data = sum_walk , aes( x = U , y = V ) ) + 
#   xlab("Starting U Coordinate") +
#   ylab("Starting Y Coordinate")
# gp_sum <- gp_sum + geom_raster(aes(fill = MeanWalkLen)) +
#   scale_fill_gradient(low = "deepskyblue", high = "black",
#                       name = "Mean Length\nto Escape",
#                       trans = "log", #Change color scale to log
#                       breaks = c(0.1,1,10,100), #Set markers on log scale
#                       limits = c(0.01,150) #Set limits (required to set markers)
#   )

# ggplot for raw data
raw_walk <- read.csv( raw_fp )
gp_raw <- ggplot(data = raw_walk , aes( x = U , y = V ) ) +
  xlab("Starting U Coordinate") +
  ylab("Starting V Coordinate")
gp_raw <- gp_raw +
  stat_summary_2d(mapping = aes(z = WalkLen),
                  bins = 100,
                  fun = median
                  ) +
  theme(legend.title = element_blank()) +
  ggtitle("Median Walk Length to Escape")

#Export to pdf file
plotpath <- paste( datadir , filename , ".pdf" , sep = "" )
pdf( plotpath ) #Open File Connection
gp_raw
dev.off() #Stop Printing

#Data Clean Up
rm( raw_walk , sum_walk , gp_raw )

