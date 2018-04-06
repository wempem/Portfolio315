set terminal postscript color
set output "search-timings.ps"
set title "Search Times"
set xlabel "Number of Searches"
set ylabel "Time (seconds)"

plot [:][:] "data/search-Small-times.data" using 1:2 with lines title "Small Search", "data/search-Medium-times.data" using 1:2 with lines title "Medium Search", "data/search-Large-times.data" using 1:2 with lines title "Large Search"

