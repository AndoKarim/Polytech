require_relative('../utils/input_configuration')

class Instruction

  def initialize(*input_model)
    @models = input_model.map { |x| InputConfiguration.new(x)}
  end


  def parse(args)
    @models.each_with_index do |model, index|
      if model.accept(args)
        @index = index
        @values = model.parse_input_array(args)

        return true
      end
    end

    false
  end
end