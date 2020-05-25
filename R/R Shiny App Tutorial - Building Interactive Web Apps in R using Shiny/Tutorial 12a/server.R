library(shiny)

shinyServer(function(input, output) {
  output$first_name <- renderText(paste("My first name is ", input$first_name))
  output$last_name <- renderText(paste("My last name is ", input$last_name))
})
