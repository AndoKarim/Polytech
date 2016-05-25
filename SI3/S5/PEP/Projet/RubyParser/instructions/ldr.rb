require_relative('loadstore')

class Ldr < LoadStore
	attr_accessor :code

	OPCODE = 0b1
	
	def initialize(args)
	    super(%w[R R R])

	    self.parse(args)

	    subcode = (OPCODE << 11) + (@values[1] << 8) + (@values[2])

	    @code = prepare_code | subcode
	end


end