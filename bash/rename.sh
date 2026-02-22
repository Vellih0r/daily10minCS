for file in ./*.jxl
do
	mv "$file" "${file%.jxl}.jpg"
done
