library(shiny)

shinyServer(
  function(input, output){
    # inputs are from ui.R
    # outputs are sued in ui.R
    output$my_name <- renderText(paste("Your name is ", input$name))
    output$my_age <- renderText(input$age)
    output$my_gender <- renderText(input$gender)
    output$num_laptop <- renderText(input$num_laptop)
    output$my_salary <- renderText(input$salary)
    output$my_state1 <- renderText(input$state1)
    output$my_state2 <- renderText(input$state2)
  }
)
