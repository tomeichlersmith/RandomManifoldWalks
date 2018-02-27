# Imports data from multiple summary files into a single plot
# Attempts to color them appropriately

# Input data files from command line
# Input files should be separated by comma and no spaces
#!/usr/bin/env Rscript
args = commandArgs(trailingOnly = TRUE)

if ( length(args) != 2 ) {
  stop("ERROR:\tInputs not formatted correctly. Should be \"File list\" \"EscapeAng List\"", call. = FALSE)
}

#Get file names list
filenames <- strsplit( args[1] , "," )
escapeangs_str <- strsplit( args[2] , "," )

filenames <- strsplit(
  "Sphere_L005_N200_S005,Sphere_L0125_N200_S005,Sphere_L015_N200_S005,Sphere_L01_N200_S005,Sphere_L02_N200_S005,Sphere_L03_N200_S005,Sphere_L04_N200_S005",
  ","
)
escapeangs_str <- strsplit(
  "0.05,0.125,0.15,0.1,0.2,0.3,0.4",
  ","
)

if ( length(filenames) != length(escapeangs_str) ) {
  stop("ERROR:\tInputs do not match in length." , call. = FALSE )
}

escapeangs <- c()
for ( ea in escapeangs_str) {
  escapeangs <- c( escapeangs , as.double(ea) )
}

#Data directory
datadir <- "~/CodeProjects/MathDHP_201718/RandomManifoldWalks/Sphere/data/"

#import data into one data.frame
walkdata <- data.frame( PolAng = double() , MeanWalkLen = double() , EscapeAng = double() )
for ( i in 1:length(filenames) ) {
    fp <- paste( datadir , filenames[i] , sep = "" )
    # Read in data
    single_df <- read.csv( fp )
    # Add Escape Angle column to this data frame
    single_df["EscapeAng"] <- NA
    single_df$EscapeAng <- escapeangs[i]
    
    #Connect this data frame to total one
    rbind( walkdata , single_df )
}

library(ggplot2)

gp <- ggplot( data = walkdata , 
              aes( x = PolAng ,
                   y = MeanWalkLen ,
                   color = EscapeAng
                   )
            ) +
  geom_point( shape = 1 , alpha = 0.2 )


