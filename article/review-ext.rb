module ReVIEW
  class Compiler
    definline :newline
  end

  class LATEXBuilder
    def inline_del(str)
      macro('sout', escape(str))
    end

    def inline_newline(str)
      "\\newline{}"
    end
  end

  class HTMLBuilder
    def inline_newline(str)
      %Q(<br />)
    end
  end
end
