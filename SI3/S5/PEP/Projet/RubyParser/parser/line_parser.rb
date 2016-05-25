require_relative('../instructions/adc')
require_relative('../instructions/add')
require_relative('../instructions/and')
require_relative('../instructions/arithmetic_shift_right_immediate')
require_relative('../instructions/arithmetic_shift_right_register')
require_relative('../instructions/b')
require_relative('../instructions/bic')
require_relative('../instructions/cmn')
require_relative('../instructions/cmp')
require_relative('../instructions/eor')
require_relative('../instructions/ldr')
require_relative('../instructions/logical_shift_left_immediate')
require_relative('../instructions/logical_shift_left_register')
require_relative('../instructions/logical_shift_right_immediate')
require_relative('../instructions/logical_shift_right_register')
require_relative('../instructions/move')
require_relative('../instructions/mul')
require_relative('../instructions/mvn')
require_relative('../instructions/orr')
require_relative('../instructions/ror')
require_relative('../instructions/rsb')
require_relative('../instructions/sbc')
require_relative('../instructions/str')
require_relative('../instructions/tst')







class LineParser

  def parse(line)
    words = line.split

    args = words[1].split(',')


    choose_parser(words[0], args).code
  end



  def choose_parser(instruction_name, args)
    case instruction_name
      when 'ADC'
        Adc.new(args)

      when 'ADD'
        Add.new(args)

      when 'AND'
        And.new(args)

      when 'ASR'
        ArithmeticShiftRightImmediate.new(args)

      when 'ASR2'
        ArithmeticShiftRightRegister.new(args)                        

      when 'B'
        B.new(args)

      when 'BIC'
        Bic.new(args) 

      when 'CMN'
        Cmn.new(args)        

      when 'CMP'
        Cmp.new(args)

      when 'EOR'
        Eor.new(args) 

      when 'LDR'
        Ldr.new(args)                      

      when 'LSL'
        LogicalShiftLeftImmediate.new(args)

      when 'LSL2'
        LogicalShiftLeftRegister.new(args)

      when 'LSR'
        LogicalShiftRightImmediate.new(args)

      when 'LSR2'
        LogicalShiftRightRegister.new(args)

      when 'MOV'
        Move.new(args)

      when 'MUL'
        Mul.new(args)

      when 'MVN'
        Mvn.new(args)

      when 'ORR'
        Orr.new(args)

      when 'ROR'
        Ror.new(args)

      when 'RSB'
        Rsb.new(args)

      when 'SBC'
        Sbc.new(args)

      when 'STR'
        Str.new(args)         

      when 'TST'
        Tst.new(args)

      else
        raise "UNKNOWN INSTRUCTION #{instruction_name}"
    end
  end
end