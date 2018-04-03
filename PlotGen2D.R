# 2-dimensional data analysis

# Input data file from command line
#!/usr/bin/env Rscript
args = commandArgs(trailingOnly = TRUE)

if ( length(args) != 2 ) {
  stop("ERROR:\tInputs not formatted correctly. Should be \"datadir filename\"", call. = FALSE)
}

# Get filename
rootdir <- "~/CodeProjects/MathDHP_201718/RandomManifoldWalks/"
datadir <- args[1]
filename <- args[2]

library(ggplot2)

#Construct file path
raw_fp <- paste( rootdir , datadir , filename , ".csv" , sep = "" )

# ggplot for raw data
raw_walk <- read.csv( raw_fp )
gp_raw <- ggplot(data = raw_walk , aes( x = U , y = V ) ) +
  xlab("Starting U Coordinate") +
  ylab("Starting V Coordinate") +
  ggtitle("Median Walk Length to Escape")
gp_raw <- gp_raw +
  stat_summary_2d(mapping = aes(z = WalkLen),
                  bins = 100,
                  fun = median
                  ) +
  scale_fill_gradient(low = "gray95",
  										high = "black",
  										trans = "log",
  										breaks = c(10,1,0.1),
  										limits = c(0.01,50)) +
  theme(legend.title = element_blank()) +
  theme_bw()

#Export to pdf file
plotpath <- paste( rootdir , datadir , filename , ".pdf" , sep = "" )
pdf( plotpath ) #Open File Connection
gp_raw
dev.off() #Stop Printing

#Data Clean Up
rm( raw_walk , gp_raw )

