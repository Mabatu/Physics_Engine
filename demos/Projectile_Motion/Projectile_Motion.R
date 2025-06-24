library("ggplot2")

myPi.data <- read.csv(file="Path//To//projectile_motion.csv")
summary(myPi.data)
head(myPi.data)
p1 <- ggplot() + geom_smooth(aes(y = Y, x = X),
                           color="orange", 
                           linewidth=1, 
                           linetype=1,
                           data = myPi.data) +
  labs( x = "x-axis",
    y = "y-axis"
  )

p1
