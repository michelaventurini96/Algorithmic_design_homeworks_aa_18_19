# Install
install.packages("wesanderson")
# Load
library(wesanderson)
library(ggplot2)

size <- c(4,8,16,32, 64,128,256,512,1024,2048,4096,8192)
time <- c(0.000004, 0.000009, 0.000024, 0.000108,0.000473, 0.002690, 0.010398,0.055386,0.453729, 5.522772, 60.097710,689.462701)
time1 <- c(0.000003, 0.000006, 0.000019, 0.000055,0.000268, 0.001732, 0.011050,0.054738,0.455215, 5.551030, 60.664831,667.209176)
time2 <- c(0.000003, 0.000005, 0.000023, 0.000074,0.000354, 0.002346, 0.009472,0.055195,0.456991, 5.319213, 56.516392,671.031331)

data = data.frame(size,time,time1)

#plot(size, time, xlab="# of matrices", ylab="Time [s]", type="l", col="blue")

g <- ggplot(data = data, aes(size, time, label<-c("# of Matrices", "Time[s]")))
g + geom_point(size = 1, colour="blue") + 
   #scale_color_gradient(low="blue", high="red")+
   geom_point(data = data, aes(size, time1), size = 1, colour="blue")+
   geom_point(data = data, aes(size, time2), size = 1, colour="blue")+
   geom_smooth(data = data, method="loess", se=TRUE, level=.90, colour="light blue", size=.5)+
   labs(x="# of Matrices", y="Time [s]", title="Chain Matrix Multiplication", subtitle="Deduction of asymptotic complexity of the algorithm")
