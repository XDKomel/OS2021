if ! [ -f text.txt ]
then
    echo "0" > text.txt;
fi

while [ $(tail -1 text.txt ) -le 999 ]
do
    if ln text.txt file.lock 
    then
        (cat text.txt | tail -n 1 | tr "\012" "+"; echo "1") | bc >> text.txt;
        rm file.lock;
    fi
done

