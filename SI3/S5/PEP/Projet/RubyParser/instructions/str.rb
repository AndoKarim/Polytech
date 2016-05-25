require_relative('loadstore')

class Str < LoadStore
	attr_accessor :code

	OPCODE = 0b0
	
	def initialize(args)
	    super(%w[R R imm5])

	    puts args

	    self.parse(args)

	    subcode = (OPCODE << 11) + (@values[2] << 6) + (@values[1] << 3) + @values[0]

	    @code = prepare_code | subcode
	end


end