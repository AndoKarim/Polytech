require_relative('instruction')


class B < Instruction
	attr_reader :code

	OPCODE_SET = 0b1101
	SIZE_OPCODE = 4
	
	def initialize(args)
	    super(%w[COMP imm8])
	    
	    self.parse(args)

	    subcode = (@values[0] << 8) + @values[1]

	    @code = (OPCODE_SET << (16 - SIZE_OPCODE)) | subcode
	end

end