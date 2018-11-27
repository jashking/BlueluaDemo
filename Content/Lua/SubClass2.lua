local ParentClass = require 'Lua.SubClass1'

local m = ParentClass:New({Super = Super})

function m:ReceiveBeginPlay()
    print('receive begin play in SubClass2')
    
    ParentClass.ReceiveBeginPlay(self)
end

return m