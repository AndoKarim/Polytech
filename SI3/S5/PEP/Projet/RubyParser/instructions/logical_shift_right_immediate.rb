require_relative('sasmc')

class LogicalShiftRightImmediate < Sasmc
  attr_accessor :code

  OPCODE = 0b001

  def initialize(args)
    super(%w[R R imm5])

    self.parse(args)

    @code = (OPCODE << 11) + (@values[2] << 6) + (@values[1] << 3) + @values[0]
  end
end