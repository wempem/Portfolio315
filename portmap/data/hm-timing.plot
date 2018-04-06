set terminal postscript color
set output "how-many-timimg.ps"
set title "How Many Timings"
set xlabel "Number of Queries"
set ylabel "Time (seconds)"

plot [:][:] "data/hm-Small-times.data" using 1:2 with lines title "Small HM", "data/hm-Medium-times.data" using 1:2 with lines title "Medium HM", "data/hm-Large-times.data" using 1:2 with lines title "Large HM"

