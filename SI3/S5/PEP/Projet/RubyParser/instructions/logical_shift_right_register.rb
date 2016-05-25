require_relative('dataprocessing')

class LogicalShiftRightRegister < DataProcessing
	attr_accessor :code

	OPCODE = 0b0011
	
	def initialize(args)
	    super(%w[R R])

	    self.parse(args)

	    subcode = (OPCODE << 6) + (@values[1] << 3) + @values[0]

	    @code = prepare_code | subcode
	end


end