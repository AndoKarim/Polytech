require_relative('instruction')

class DataProcessing < Instruction

	OPCODE_SET = 0b010000
	SIZE_OPCODE = 6

	def prepare_code
		OPCODE_SET << (16 - SIZE_OPCODE)
	end

end