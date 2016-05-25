require_relative('instruction_helper')

class InputConfiguration

  SIZE_OF_REGISTER = 3 # bits
  COMPS = { "EQ" => 0b0000, 
		"NE" => 0b0001, 
		"CS" => 0b0010, 
		"HS" => 0b0010, 
		"CC" => 0b0011, 
		"LO" => 0b0011, 
		"MI" => 0b0100, 
		"PL" => 0b0101, 
		"VS" => 0b0110, 
		"VC" => 0b0111, 
		"HI" => 0b1000, 
		"LS" => 0b1001, 
		"GE" => 0b1010, 
		"LT" => 0b1011, 
		"GT" => 0b1100, 
		"LE" => 0b1101, 
		"AL" => 0b1110, 
		"NV" => 0b1111 }

  def initialize(array)
    @pattern = array.map do |item|
      if item == 'R'
        item.to_sym

      elsif item =~ /imm[0-9]+/
        item.tr('/^[a-z]/', '')

      elsif item == 'COMP'
      	item.to_sym
      else
        raise "Unknown pattern: #{item}"
      end
    end
  end

	
 def accept(array)
    return false if array.length != @pattern.length

    (0..array.length-1).each do |i|
      register_check = @pattern[i] == :R && InstructionHelper::is_a_register(array[i])
      number_check = @pattern[i] =~ /[0-9]+/ && array[i] =~ /[0-9]+/
      comp_check = @pattern[i] == :COMP && COMPS.has_key?(array[i])

      return false unless register_check || number_check || comp_check
    end

    true
  end

  def parse_input_array(array)
    (0..array.length-1).each_with_index do |i|
      if @pattern[i] == :R
        array[i] = InstructionHelper::parse_register(array[i])
        raise 'Invalid register: index not in authorized range' unless (0..2**SIZE_OF_REGISTER-1).include?(array[i])

      elsif @pattern[i] =~ /[0-9]+/  # pattern = imm*
        array[i] = array[i].to_i
        raise "Invalid immediate: not in authorized range (#{array[i]} > #{2**@pattern[i].to_i-1})" unless (0..2**@pattern[i].to_i-1).include?(array[i])

    else 
    	array[i] = COMPS[array[i]]

      end
    end

    array
  end
end