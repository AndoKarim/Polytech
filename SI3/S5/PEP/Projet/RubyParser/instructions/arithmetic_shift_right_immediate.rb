require_relative('sasmc')

class ArithmeticShiftRightImmediate < Sasmc
  attr_accessor :code

  OPCODE = 0b010

  def initialize(args)
    super(%w[R R imm5])

    self.parse(args)

    subcode = (OPCODE << 11) + (@values[2] << 6) + (@values[1] << 3) + @values[0]
    @code = prepare_code | subcode
  end

end