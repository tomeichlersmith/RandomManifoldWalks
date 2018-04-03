# 2-dimensional data analysis

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
datadir <- "~/CodeProjects/MathDHP_201718/RandomManifoldWalks/Torus/data/"
raw_fp <- paste( datadir , filename , ".csv" , sep = "" )

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
rm( raw_walk , gp_raw )

