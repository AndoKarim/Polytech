require_relative('sasmc')

class Subtract < Sasmc
  attr_accessor :code

  OPCODE = [0b01101] # SUB_REGISTER, SUB_3BITS_IMMEDIATE, SUB_8BITS_IMMEDIATE

  def initialize(args)
    super(%w[R R R])

    self.parse(args)

    subcode = (OPCODE[@index] << 11) + (@values[0] << 8) + @values[1]

    @code = prepare_code | subcode

  end

end