
g++ -O2 -lm -std=c++14 -o bl bl.cpp
g++ -O2 -lm -std=c++14 -o std main.cpp

t=0
while true;do
  ((t++))
  python3 gen.py > in.txt
  ./bl < in.txt > bl.txt
  ./std < in.txt > std.txt
  # diff bl.txt std.txt
  if (diff bl.txt std.txt) then
    printf "%d: AC\n" t
  else
    printf "%d: WA\n" t
    break
  fi
  sleep 0.1
done