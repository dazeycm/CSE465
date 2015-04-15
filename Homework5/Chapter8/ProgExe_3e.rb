k = 5

case k
when 1, 2
j = 3 * k - 1
when 3, 5
j = 3 * k + 1
when 4
j = 4 * k - 1
when 6, 7, 8
j = k - 2
else
puts "error"
end

puts j
