%x(t) assigned in the HW8
function x = f(t)
x = (cos(10 * pi * t) + 2 * sin(30 * pi * t)) .* (0<=t & t<5) + cos(40 * pi * t) .* (5<=t & t<10) + (cos(60 * pi *t) + 0.6 * sin(90 * pi * t)) .* (10<=t & t<15) + sin(100 * pi * t) .* (15<=t & t<20);