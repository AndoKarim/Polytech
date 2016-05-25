module InstructionHelper

  def self.is_a_register(arg)
    arg =~ /R[0-9]+/
  end

  def self.is_an_immediate_number(arg)
    arg =~ /[0-9]*/
  end



  def self.parse_register(register)
    raise 'Not a register' unless self.is_a_register(register)

    register[1..-1].to_i
  end
end