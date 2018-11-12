local m = {}

local Super = Super
local print = print
local loadClass = loadClass

-- Override UserWidget Construct Event
function m:Construct()
    print('LuaUseCaseWidget Construct')

    -- load UTestObject's class
    local TestObjectClass = loadClass('TestObject')

    -- new a UTestObject instance
    local TestObjectInstance = TestObjectClass()
    print('TestObjectInstance is', tostring(TestObjectInstance))

    -- write to parent's class member
    Super.StrValue = 'StrValue'

    -- binding delegate to parent widget's button
    Super.Button1.OnClicked:Add(function() print('Button1 OnClicked') end)
end

-- Override UserWidget Destruct Event
function m:Destruct()
    print('LuaUseCaseWidget Destruct')
end

-- Override UseCaseWidget TestScriptFunction Event
function m:TestScriptFunction()
    print('Lua TestScriptFunction get called')

    -- call parent's TestFunction
    local v = Super:TestFunction()
    return v
end

-- Override UseCaseWidget TestScriptFunctionWithParam Event
function m:TestScriptFunctionWithParam(Param1, Param2)
    print('Lua TestScriptFunctionWithParam get called')
    print('Param1 is', Param1)
    print('Param2 is', Param2.X, Param2.Y, Param2.Z)

    -- call parent's TestFunctionWithParam
    local v = Super:TestFunctionWithParam(Param1, Param2)
    return v
end

return m