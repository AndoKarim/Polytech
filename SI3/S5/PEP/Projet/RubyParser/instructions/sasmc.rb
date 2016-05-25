require_relative('instruction')

class Sasmc < Instruction

	OPCODE_SET = 0b00
	SIZE_OPCODE = 2

	def prepare_code
		OPCODE_SET << (16 - SIZE_OPCODE)
	end

end