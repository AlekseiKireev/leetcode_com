https://leetcode.com/problems/robot-bounded-in-circle/

https://walkccc.me/LeetCode/problems/1041/

У Федора Меньшикова разбор отсут-т!

___________

Figure 3. After 4 cycles the limit cycle trajectory returns to the initial point x = 0, y = 0.

We do not need to run 4 cycles to identify the limit cycle trajectory.
One cycle is enough. There could be two situations here.

First, if the robot returns to the initial point after one cycle,
that's the limit cycle trajectory.

Second, if the robot doesn't face north at the end of the first cycle,
that's the limit cycle trajectory.
Once again, that's the consequence of the plane symmetry for the repeated cycles [proof].

Appendix: Mathematical Proof
Let's provide a strict mathematical proof.

If the robot doesn't face north at the end of the first cycle, then that's the limit cycle trajectory.

First, let's check which direction the robot faces after 4 cycles.

Let's use numbers from 0 to 3 to mark the directions:
north = 0, east = 1, south = 2, west = 3.
After one cycle the robot is facing direction k != 0.

After 4 cycles, the robot faces direction (k * 4) % 4 = 0, i.e.
after 4 cycles, the robot is always facing north.

Second, let's find the robot coordinates after 4 cycles.

The robot initial coordinates are x = y = 0. After one cycle,
the new coordinates are x1=x+Δxx_1 = x + \Delta xx 
1
​
 =x+Δx, y1=y+Δyy_1 = y + \Delta yy 
1
​
 =y+Δy, where
both Δx\Delta xΔx and Δy\Delta yΔy could be positive or negative.

Let's consider four situations.

After one cycle, the robot faces north.
Then here is what we have after 4 cycles:

x4=x+Δx+Δx+Δx+Δx=x+4Δxx_4 = x + \Delta x + \Delta x + \Delta x + \Delta x = x + 4 \Delta xx 
4
​
 =x+Δx+Δx+Δx+Δx=x+4Δx

y4=y+Δy+Δy+Δy+Δy=y+4Δyy_4 = y + \Delta y + \Delta y + \Delta y + \Delta y = y + 4 \Delta yy 
4
​
 =y+Δy+Δy+Δy+Δy=y+4Δy

After one cycle, the robot faces east.
Then here is what we have after 4 cycles:

x4=x+Δx+Δy−Δx−Δy=xx_4 = x + \Delta x + \Delta y - \Delta x - \Delta y = xx 
4
​
 =x+Δx+Δy−Δx−Δy=x

y4=y+Δy−Δx−Δy+Δx=yy_4 = y + \Delta y - \Delta x - \Delta y + \Delta x = yy 
4
​
 =y+Δy−Δx−Δy+Δx=y

After one cycle, the robot faces south.
Then here is what we have after 4 cycles:

x4=x+Δx−Δx+Δx−Δx=xx_4 = x + \Delta x - \Delta x + \Delta x - \Delta x = xx 
4
​
 =x+Δx−Δx+Δx−Δx=x

y4=y+Δy−Δy+Δy−Δy=yy_4 = y + \Delta y - \Delta y + \Delta y - \Delta y = yy 
4
​
 =y+Δy−Δy+Δy−Δy=y

After one cycle, the robot faces west.
Then here is what we have after 4 cycles:

x4=x+Δx−Δy−Δx+Δy=xx_4 = x + \Delta x - \Delta y - \Delta x + \Delta y = xx 
4
​
 =x+Δx−Δy−Δx+Δ
