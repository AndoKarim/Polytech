require_relative('sasmc')

class Move < Sasmc
  attr_accessor :code

  OPCODE = 0b100

  def initialize(args)
    super(%w[R imm8])

    self.parse(args)

    subcode = (OPCODE << 11) + (@values[0] << 8) + @values[1]
    @code = prepare_code | subcode
  end

end