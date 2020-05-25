library(shiny)

shinyServer(function(input, output) {
    output$my_first_name <- renderText({
      paste("My first name is", input$first_name)
    })

    output$my_last_name <- renderText({
      input$action
      # isolate function is used to create dependency on the action button
      # if isolate is not used, text will be displayed reactively as soon as
      # user inputs the text
      isolate(paste("My last name is", input$last_name))
    })
})
