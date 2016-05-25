require_relative('sasmc')

class LogicalShiftLeftImmediate < Sasmc
  attr_accessor :code

  OPCODE = 0b000

  def initialize(args)
    super(%w[R R imm5])

    self.parse(args)

    subcode = (OPCODE << 11) + (@values[2] << 6) + (@values[1] << 3) + @values[0]
    @code = prepare_code | subcode
  end

end