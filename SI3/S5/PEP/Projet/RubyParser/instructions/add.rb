require_relative('sasmc')

class Add < Sasmc
  attr_accessor :code

  OPCODE = 0b01100 
  
  def initialize(args)
    super(%w[R R R])

    self.parse(args)
    
    subcode = (OPCODE << 9) + (@values[2] << 6) + (@values[1] << 3) + @values[0]


    @code = prepare_code | subcode
  end

end
