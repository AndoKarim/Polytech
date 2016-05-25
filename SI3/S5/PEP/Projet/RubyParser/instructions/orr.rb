require_relative('dataprocessing')

class Orr < DataProcessing
	attr_accessor :code

	OPCODE = 0b1100
	
	def initialize(args)
	    super(%w[R R])

	    self.parse(args)

	    subcode = (OPCODE << 6) + (@values[1] << 3) + @values[0]

	    @code = prepare_code | subcode
	end


end