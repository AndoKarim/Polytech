require_relative('instruction')

class LoadStore < Instruction

	OPCODE_SET = 0b0110
	SIZE_OPCODE = 4

	def prepare_code
		OPCODE_SET << (16 - SIZE_OPCODE)
	end

end