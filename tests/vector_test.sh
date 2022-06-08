
echo "====================begin test=============================="
c++ -Wall -Wextra -Werror ../mains/main.cpp -o a.out
c++ -Wall -Wextra -Werror ../mains/main1.cpp -o b.out



./a.out > a
./b.out > b
a=a
b=b
if cmp -s "$a" "$b"; then
    echo Same
else
    echo Differ
fi

rm -rf ../a.out ../b.out ../a ../b

