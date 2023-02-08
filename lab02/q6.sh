echo "task6"
echo "Enter a number: "
read number
function fib
{
  x=0
  y=1
  i=2
  echo "Fibonacci Series up to $number terms :"
  echo "$x"
  echo "$y"
  while [ $i -lt $number ]
  do
      i=`expr $i + 1 `
      z=`expr $x + $y `
      echo "$z"
      x=$y
      y=$z
  done
}
r=`fib $number`
echo "$r"
