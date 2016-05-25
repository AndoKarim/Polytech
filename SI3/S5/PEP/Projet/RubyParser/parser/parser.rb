require_relative('line_parser')

class Parser



  ##### EXECUTION #####

  line_parser = LineParser.new

  puts 'v2.0 raw'
  ARGF.each_line do |line|
    puts line_parser.parse(line).to_s(16)
  end
end