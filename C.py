from turtle import *


#黄色爱心铃铛
 
pensize(5)
seth(0)
color('orange')
begin_fill()
lt(135)
fd(22)
right(180)#画笔掉头
circle(8,-180)
 
 
backward(8)
right(90)
forward(8)
circle(-8,180)
fd(22)
 
end_fill()
hideturtle()