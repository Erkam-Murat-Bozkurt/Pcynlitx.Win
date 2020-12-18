
Write-Output ""

Write-Output ""

Write-Output "   # The construction of the project directories started .."

$Condition = Test-Path -Path 'D:\PCYNLITX.WIND.IMPL.LIBRARY'

if ( -not $Condition )
{
     mkdir D:\PCYNLITX.WIND.IMPL.LIBRARY
}

$Condition = Test-Path -Path 'D:\PCYNLITX.WIND.IMPL.LIBRARY\PROJECT.HEADER.FILES'

if ( -not $Condition )
{
     mkdir D:\PCYNLITX.WIND.IMPL.LIBRARY\PROJECT.HEADER.FILES
}

$Condition = Test-Path -Path 'D:\PCYNLITX.WIND.IMPL.LIBRARY\PROJECT.LIBRARY'

if ( -not $Condition )
{
     mkdir D:\PCYNLITX.WIND.IMPL.LIBRARY\PROJECT.LIBRARY
}

$Condition = Test-Path -Path 'D:\PCYNLITX.WIND.IMPL.LIBRARY\PROJECT.LIBRARY\OBJECT.FILES'

if ( -not $Condition  )
{
    mkdir D:\PCYNLITX.WIND.IMPL.LIBRARY\PROJECT.LIBRARY\OBJECT.FILES
}

Write-Output ""

Write-Output ""

Write-Output "   The project directories have been constructed :-)"

Write-Output ""
